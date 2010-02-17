# This file is part of babel4iphone.

# Copyright (C) 2009 Giovanni Amati <amatig@gmail.com>

# babel4iphone is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# babel4iphone is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with babel4iphone.  If not, see <http://www.gnu.org/licenses/>.


import time

class Reactor(object):
    
    def __init__(self):
        self.__fn = []
    
    def callLater(self, t, fn, *args):
        self.__fn.append((time.time() + t, fn, args))
    
    def step(self):
        if self.__fn:
            fn = self.__fn.pop(0)
            if time.time() >= fn[0]:
                try:
                    fn[1](*fn[2])
                except Exception, e:
                    print "No callable method"
            else:
                self.__fn.append(fn)

reactor = Reactor()
