// This file is part of babel4iphone.

// Copyright (C) 2009 Giovanni Amati <amatig@gmail.com>

// babel4iphone is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// babel4iphone is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with babel4iphone.  If not, see <http://www.gnu.org/licenses/>.


#ifndef __SHARED_DATA_H__
#define __SHARED_DATA_H__

#define HOST		"127.0.0.1"
#define PORT		66666
#define DELIMETER	"\r\n"
#define DATABASE	"gameDB.sqlite"

#import <CFNetwork/CFNetwork.h>
#import <sqlite3.h>
#import "CoreFunctions.h"

@interface SharedData : NSObject
{
	sqlite3 *database;
	NSInputStream *inputStream;
	NSOutputStream *outputStream;
}

-(void) connectToDatabase;
-(NSMutableArray *) execQuery:(NSString *)sqlStatement;
-(NSMutableArray *) getCharInfo:(NSString *)race job:(NSString *)job level:(int)level supjob:(NSString *)supjob suplevel:(int)suplevel;

-(void) connectToServer;
-(void) sendToServer:(NSString *)cmd;
-(void) stream:(NSStream *)stream handleEvent:(NSStreamEvent)streamEvent;

+(SharedData *) Initialize;

@end

#endif
