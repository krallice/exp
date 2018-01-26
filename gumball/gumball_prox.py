#!/usr/bin/python

import json
from gumball_state import GumballMachine

# Proxy Design Pattern
class GumballMonitor(object):

    def __init__(self, gumballmachine):

        self.machine = gumballmachine

    def report(self):

        print 'Gumball Machine: %s' % (self.machine.get_location())
        print 'Gumball State: %s' % (self.machine.get_state())
        print 'Gumball Count: %s' % (self.machine.get_count())

# Composite Design Pattern:
# (Composite of Proxies)
class GumballSuperMonitor(object):

    def __init__(self, gumballmachinelist):

        self.list = []
        for machine in gumballmachinelist:
            self.list.append(GumballMonitor(machine))

    def report(self):

        for index, gbm in enumerate(self.list):
            print
            print "Gumball Machine #%s" % (index)
            gbm.report()

# Decorator:
# Decorator of Composite of Proxies
class GumballSuperMonitorJSON(GumballSuperMonitor):

    def __init__(self, gbsm):

        self.gbsm = gbsm
        
    def report(self):

        print "{"
        print ' "faked json": "'
        self.gbsm.report()
        print '"'
        print '}'

if __name__ == "__main__":

    gb_list = []

    gb_list.append(GumballMachine(6, "Smithfield"))
    gb_list.append(GumballMachine(4, "Camperdown"))
    gb_list.append(GumballMachine(5, "Fairfield"))

    gbsm = GumballSuperMonitor(gb_list)
    gbsm.report()
    print

    gb_list[1].insert_quarter()

    print
    print
    print "JSON Decorator: GumballSuperMonitorJSON"
    gbsm_j = GumballSuperMonitorJSON(gbsm)
    gbsm_j.report()
    print
