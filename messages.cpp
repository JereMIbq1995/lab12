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

#include <string>     // for convenience
#include <list>       // to store the messages
#include <iostream>   // standard input and output
#include <fstream>    // the messages are read from a file
#include <cassert>    // because I am paraniod
#include "control.h"  // all the Bell-LaPadula code
#include "message.h"  // all the code about a single message
#include "messages.h" // a collection messages

using namespace std;

/***********************************************
 * MESSAGES :: DISPLAY
 * display the list of messages
 ***********************************************/
void Messages::display(const Control &subjectControl) const
{
   for (list <Message> :: const_iterator it = messages.begin();
        it != messages.end();
        ++it)
      it->displayProperties(subjectControl);
}

/***********************************************
 * MESSAGES :: SHOW
 * show a single message
 **********************************************/
void Messages::show(int id, const Control &subjectControl) const
{
   for (list <Message> :: const_iterator it = messages.begin();
        it != messages.end();
        ++it)
      if (it->getID() == id)
         it->displayText(subjectControl);
}

/***********************************************
 * MESSAGES :: UPDATE
 * update one single message
 ***********************************************/
void Messages::update(int id, const string & text, 
                     const Control &subjectControl)
{
   for (list <Message> :: iterator it = messages.begin();
        it != messages.end();
        ++it)
      if (it->getID() == id)
         it->updateText(text, subjectControl);
}

/***********************************************
 * MESSAGES :: REMOVE
 * remove a single message
 **********************************************/
void Messages::remove(int id, const Control &subjectControl)
{
   for (list <Message> :: iterator it = messages.begin();
        it != messages.end();
        ++it)
      if (it->getID() == id)
         it->clear(subjectControl);
}

/***********************************************
 * MESSAGES :: ADD
 * add a new message
 **********************************************/
void Messages::add(const string & text,
                   const string & author,
                   const string & date,
                   const Control &assetControl)
{
   Message message(text, author, date, assetControl);
   messages.push_back(message);
}

/***********************************************
 * MESSAGES :: READ MESSAGES
 * read the messages from a file
 ***********************************************/
void Messages::readMessages(const char * fileName)
{
   // open the file
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "ERROR! Unable to open file "
           << fileName
           << endl;
      return;
   }

   // continue reading until we fail
   while (!fin.fail() && !fin.eof())
   {
      string author;
      string date;
      string text;
      string textControl;
      getline(fin, textControl, '|');
      getline(fin, author, '|');
      getline(fin, date, '|');
      getline(fin, text);

      Control numControl = textToNumControl(textControl);
      if (!fin.fail())
      {
         Message message(text, author, date, numControl);
         messages.push_back(message);
      }
   }

   // close up shop!
   fin.close();
}

/***********************************************
 * Convert control of type string into type Control
 *  If the string is not recognizable, assume
 *  that it's at the highest level of confidentiality
 * author: Jeremy Duong
 * *********************************************/
Control Messages::textToNumControl(const string &control)
{
   ControlMap controlMap;
   return controlMap.getControlNum(control); //In time of war, it's better safe than sorry
}