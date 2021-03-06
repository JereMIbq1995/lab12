/***********************************************************************
* COMPONENT:
*    MESSAGE
* Author:
*    Jeremy Duong
*    Austin Lundberg
*    Timothy Stephenson
*    Gabriel Sanahuano
*    Sophia Pearson
*    David Headrick
* Summary: 
*    This class stores the notion of a message
************************************************************************/

#pragma once

#include <string>     // for convenience
#include "control.h"  // for all the control stuff


/**************************************************
 * MESSAGE
 * one message to be displayed to the user or not
 **************************************************/
class Message
{
public:
   // default constructor for an empty message
   Message();

   // the most commonly used constructor: create a message
   Message(const std::string & text,
           const std::string & author,
           const std::string & date,
           const Control &assetControl);

   // determine the unique ID of this message
   int getID() const { return id; }

   // display the properties but not content of the message
   void displayProperties(const Control &subjectControl) const;

   // display the content of the message
   void displayText(const Control &subjectControl) const;

   // update the text componnet of the message
   void updateText(const std::string & newText, const Control &subjectControl);

   // return the control level of the asset
   Control getControl() const;

   // clear out a message
   void clear(const Control &subjectControl);
   
private:
   int id;                   // the unique ID of this message
   static int idNext;        // the id of the next message created
   bool empty;               // is this message empty / cleared?
   std::string text;         // the textual content of this message
   std::string author;       // the author of this message
   std::string date;         // the date this message was created
   Control assetControl;     // the control level of the message
};