#!/usr/bin/python

import re
import requests
from lxml import html

class Album(object):
    """
    Album data and methods

    """
    def __init__(self, input_string, delim=" - "):

        # Splice our flat string into a dict for assigning self variables:
        input_dict = {}
        input_dict = self._splice_combined_string(input_string, delim)

        self.artist = input_dict["artist"]
        self.album = input_dict["album"]

    def _splice_combined_string(self, input_string, delim=" - "):
        """ 
        Split 'Album'delim'Artist' string, and return a dict
        
        :param input_string: <str> Input string, in 'Album - Artist' format
        :param delim: (Optional) <str> Optional delimiter to split by
        :return: <dict>
        """
        ret = {
            "artist": "",
            "album": ""
        }

        split_string = input_string.split(delim)
        ret["artist"] = split_string[0]
        ret["album"] = split_string[1]

        return ret

    def __str__(self):
        return str(self.__dict__)

class ArtworkFetcher(object):
    """ 
    Abstract Base Class for our fetcher implementations
    """

    def __init__(self):
        raise NotImplementedError

    def get_artwork_url(self, album):
        """
        Search for our album art, and return an url as string

        :param album: <Album> Our Album object to search service for
        :return: <str> URL where art is located
        """
        raise NotImplementedError

    def __str__(self):
        return str(self.__dict__)

class LastFMFetcher(ArtworkFetcher):
    """
    Concrete Class for Scraping Last.fm Services (naughty)
    """

    def __init__(self):

        self.base_url = "https://www.last.fm/music"
        self.meta_xpath_img = "/html/head/meta[@property='og:image']"

    def get_artwork_url(self, album):
        """
        Search for our album art, and return an url as string

        :param album: <Album> Our Album object to search service for
        :return: <str> URL where art is located
        """

        request_url = self.base_url + "/" + album.artist + "/" + album.album
        r = requests.get(request_url)

        tree = html.fromstring(r.content)
        raw_img_url = tree.xpath(self.meta_xpath_img)
        for r in raw_img_url:
            artwork_url = r.get("content")
            break
        
        # Check to see if the url is a file of some sort?
        match = re.search("\.[a-zA-Z]{3,4}$", artwork_url)
        if match:
            return artwork_url
        else:
            return ''

class FetcherEngine(object):
    """
    Fetcher Engine, for fetching album art.
    Strategy Design Pattern used to abstract API/Service used to fetch art
    through ArtworkFetcher Classes
    """

    def __init__(self):
        """
        Set default strategy (LastFM)
        """
        last_fm = LastFMFetcher()
        self.strategy = last_fm

    def set_lastfm(self):
        self.strategy = last_fm

    def get_artwork_url(self, album):
        url = self.strategy.get_artwork_url(album)
        return url

if __name__ == "__main__":

    #<img src="https://lastfm-img2.akamaized.net/i/u/ar0/05d19b134e564d73cdc76117ca426b89.jpg" height="256" width="256" />

    fetcher = FetcherEngine()

    with open("raw.txt", "r") as rawfile:
        for rawline in rawfile:

            # Strip newlines:
            rawline = rawline.rstrip()

            # Parsing one of our album names?:
            if "[" and "]" in rawline:

                # Create album object and fetch our artwork:
                album = Album(rawline[4:])
                album_art_url = fetcher.get_artwork_url(album)

                # Add our image tag:
                print "<img src='%s' height='128' width='128' />%s" % (album_art_url, rawline)

            # Otherwise, pass:
            else:
                print rawline

    """
    input_strings = [   "Miles Davis - Sorcerer", 
                        "Krallice - Diotima",
                        "Artificial Brain - Infared Horizon",
                        "Artificial Brain - Infrared Horizon",
                        "The Hotelier - Home, Like Noplace Is There",
                        "Altar Of Plagues - Teethed Glory and Injury",
                        "Yellow Eyes - Immersion Trench Reverie",
                        "Foxing - The Albatross",
                        "Talk Talk - Laughing Stock",
                        "Wolves in the Throne Room - Celestial Lineage",
                        "Algernon Cadwallader - Some Kind of Cadwallader" ]

    fetcher = FetcherEngine()
    for i in input_strings:
        album = Album(i)
        print i
        print fetcher.get_artwork_url(album)
    """
