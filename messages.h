/***********************************************************************
 * COMPONENT:
 *    MESSAGES
 * Author:
 *    Jeremy Duong
 *    Austin Lundberg
 *    Timothy Stephenson
 *    Gabriel Sanahuano
 *    Sophia Pearson
 *    David Headrick
 * Summary:
 *    This class stores the notion of a collection of messages
 ************************************************************************/

#pragma once

#include <string>     // for convenience
#include <list>       // to store the messages
#include "control.h"  // all the Bell-LaPadula code
#include "message.h"  // all the code about a single message

/***********************************************
 * MESSAGES
 * The collection of high-tech messages
 ***********************************************/
class Messages
{
public:
   // constructor: read a file to fill the messages
   Messages(const char * fileName) { readMessages(fileName); }

   // display the list of messages
   void display(const Control &subjectControl) const;

   // show a single message
   void show(int id, const Control &subjectControl) const;

   // update one single message
   void update(int id,
               const std::string & text,
               const Control &subjectControl);

   // remove a single message
   void remove(int id, const Control &subjectControl);

   // add a new message
   void add(const std::string & text,
            const std::string & author,
            const std::string & date,
            const Control &subjectControl);

private:
   // the list of messages
   std::list <Message> messages;

   // read the messages from a file
   void readMessages(const char * fileName);

   // convert Control of type string into Control of type Control
   Control textToNumControl(const std::string &control);
};