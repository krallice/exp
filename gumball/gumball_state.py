#!/usr/bin/python


class GumballState(object):

    def __init__(self, gumballmachine):
        self.gumballmachine = gumballmachine

    def insert_quarter():
        pass

    def eject_quarter():
        pass

    def turn_crank():
        pass

    def dispense():
        pass

class NoQuarterState(GumballState):

    def insert_quarter(self):
        print "You inserted a quarter"
        self.gumballmachine.state = self.gumballmachine.has_quarter_state

    def eject_quarter(self):
        print "No quarter inserted braa"

    def turn_crank(self):
        print "You turned the crank, but there isnt any quarter"

    def dispense(self):
        print "Gotta pay first cheapskate"

class HasQuarterState(GumballState):

    def insert_quarter(self):
        print "Quarter already inserted!"

    def eject_quarter(self):
        print "Returning Quarter"
        self.gumballmachine.state = self.gumballmachine.no_quarter_state

    def turn_crank(self):
        print "Crank Turning"
        self.gumballmachine.state = self.gumballmachine.sold_state

    def dispense(self):
        print "No Gumball dispensed"

class SoldState(GumballState):
    
    def insert_quarter(self):
        print "Please wait while we dispense your gumball"

    def eject_quarter(self):
        print "Too late how bad too sad"

    def turn_crank(self):
        print "No double spinnin"

    def dispense(self):
        self.gumballmachine.release_ball()
        if self.gumballmachine.count > 0:
            self.gumballmachine.state = self.gumballmachine.no_quarter_state
        else:
            print "Out of gumballs"
            self.gumballmachine.state = self.gumballmachine.sold_out_state

class SoldOutState(GumballState):
    
    def insert_quarter(self):
        print "No Gumballs Left"

    def eject_quarter(self):
        print "No Gumballs Left"

    def turn_crank(self):
        print "No Gumballs Left"

    def dispense(self):
        print "No Gumballs Left"

class GumballMachine(object):

    def __init__(self, count=2):

        self.count = count
        self.has_quarter_state = HasQuarterState(self)
        self.no_quarter_state = NoQuarterState(self)
        self.sold_state = SoldState(self)
        self.sold_out_state = SoldOutState(self)

        self.state = self.no_quarter_state

    def insert_quarter(self):

        self.state.insert_quarter()

    def eject_quarter(self):
        
        self.state.eject_quarter()

    def turn_crank(self):

        self.state.turn_crank()
        self.state.dispense()

    def release_ball(self):

        print "Releasing Gumball"
        self.count = self.count - 1

if __name__ == "__main__":

    gb = GumballMachine()
    gb.insert_quarter()
    gb.insert_quarter()
    gb.insert_quarter()
    gb.eject_quarter()
    gb.eject_quarter()
    gb.insert_quarter()
    gb.insert_quarter()
    gb.turn_crank()
    gb.turn_crank()
    gb.insert_quarter()
    gb.turn_crank()
    gb.insert_quarter()
    gb.turn_crank()

    gb.insert_quarter()
    gb.turn_crank()
    gb.insert_quarter()
    gb.turn_crank()
    gb.insert_quarter()
    gb.turn_crank()
