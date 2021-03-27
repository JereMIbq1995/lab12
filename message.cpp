/***********************************************************************
 * COMPONENT:
 *    MESSAGE
 * Author:
 *    Br. Helfrich, <your name here if you made a change>
 * Summary:
 *    This class stores the notion of a message
 ************************************************************************/

#include <iostream>   // standard input and output
#include <cassert>    // because I am paraniod
#include "message.h"  // for the header file
using namespace std;

/**************************************************
 * MESSAGE DEFAULT CONSTRUCTOR
 * Set a message to empty
 **************************************************/
Message ::  Message()
{
   empty = true;
   text = "Empty";
   id = idNext++;
   assetControl = SECRET; //Again, assume it's secret to be safe
}


/**************************************************
 * MESSAGE NON-DEFAULT CONSTRUCTOR
 * Create a message and fill it
 **************************************************/
Message::Message(const string & text,
                 const string & author,
                 const string & date,
                 const Control & assetControl)
{
   this->text = text;
   this->author = author;
   this->date = date;
   this->id = idNext++;
   this->assetControl = assetControl;
   empty = false;
}

/**************************************************
 * MESSAGE :: DISPLAY PROPERTIES
 * Display the attributes/properties but not the
 * content of this message
 **************************************************/
void Message::displayProperties(const Control &subjectControl) const
{
   // skip this one if there is nothing to see, or if user has no permission
   if (empty || !securityConditionRead(this->assetControl, subjectControl))
      return;
   
   // display the message
   cout << "\t[" << id << "] ";
      cout << "Message from " << author << " at " << date;
   cout << endl;
}

/**************************************************
 * MESSAGE :: DISPLAY TEXT
 * Display the contents or the text of the message
 **************************************************/
void Message::displayText(const Control &subjectControl) const
{
   // Display only if user has permission
   if (securityConditionRead(this->assetControl, subjectControl))
   {
      cout << "\tMessage: "
         << text
         << endl;
   }
   else
   {
      cout << "Cannot find message!" << endl;
   }
}

/**************************************************
 * MESSAGE :: UPDATE TEXT
 * Update the contents or text of the message
 **************************************************/
void Message::updateText(const string & newText, const Control &subjectControl)
{
   if (securityConditionWrite(this->assetControl, subjectControl))
   {
      text = newText;
      cout << "Update successful!" << endl;
   }
   else
   {
      cout << "Cannot update this message!" << endl;
   }
}

/**************************************************
 * MESSAGE :: GET CONTROL
 * Return the control level of the asset
 *************************************************/
Control Message::getControl() const {
   return this->assetControl;
}

/**************************************************
 * MESSAGE :: CLEAR
 * Delete the contents of a message and mark it as empty
 *************************************************/
void Message::clear(const Control &subjectControl)
{
   if (securityConditionWrite(this->assetControl, subjectControl))
   {
      text = "Empty";
      author.clear();
      date.clear();
      empty = true;
   }
   else
   {
      cout << "Cannot clear this message!" << endl;
   }
}

int Message::idNext = 100;