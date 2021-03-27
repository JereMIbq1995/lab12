/***********************************************************************
 * COMPONENT:
 *    INTERACT
 * Author:
 *    Jeremy Duong
 *    Austin Lundberg
 *    Timothy Stephenson
 *    Gabriel Sanahuano
 *    Sophia Pearson
 *    David Headrick
 * Summary:
 *    This class allows one user to interact with the system
 ************************************************************************/

#include <iostream>   // standard input and output
#include <string>     // for convenience
#include <cassert>    // because I am paraniod
#include <stdlib.h>   // for atoi 
#include "messages.h" // to interact with the collection of messages
#include "control.h"  // all the Bell-LaPadula stuff
#include "interact.h" // the interact class and User structure

using namespace std;

/**************************************************************
 * USERS
 * All the users currently in the system
 *************************************************************/
const User users[] =
{
   { "AdmiralAbe",     "password", SECRET },  
   { "CaptainCharlie", "password", PRIVILEGED }, 
   { "SeamanSam",      "password", CONFIDENTIAL },
   { "SeamanSue",      "password", CONFIDENTIAL },
   { "SeamanSly",      "password", CONFIDENTIAL }
};

const int ID_INVALID = -1;

/****************************************************
 * INTERACT constructor
 * Authenticat ethe user and get him/her all set up
 ***************************************************/
Interact::Interact(const string & userName,
                   const string & password,
                   Messages & messages)
{
   this->subjectControl = authenticate(userName, password);
   this->userName = userName;
   this->pMessages = &messages;
}

/****************************************************
 * INTERACT :: SHOW
 * show a single message
 ****************************************************/
void Interact::show() const
{
   pMessages->show(promptForId("display"), this->subjectControl);
}
   
/****************************************************
 * INTERACT :: DISPLAY
 * display the set of messages
 ***************************************************/
void Interact::display() const
{
   pMessages->display(this->subjectControl);
}

/****************************************************
 * INTERACT :: ADD
 * add a single message
 ****************************************************/
void Interact::add()
{
   pMessages->add(promptForLine("message"),
                  userName,
                  promptForLine("date"),
                  this->subjectControl);
}

/****************************************************
 * INTERACT :: UDPATE
 * update a single message
 ****************************************************/
void Interact::update()
{
   int id = promptForId("update");
   pMessages->update(id,
                     promptForLine("message"),
                     this->subjectControl);
}

/****************************************************
 * INTERACT :: REMOVE
 * remove one message from the list
 ***************************************************/
void Interact::remove()
{
   pMessages->remove(promptForId("delete"), this->subjectControl);
}

/****************************************************
 * INTERACT :: DISPLAY USERS
 * display the set of users in the system
 ***************************************************/
void displayUsers()
{
   for (int idUser = 0; idUser < sizeof(users) / sizeof(users[0]); idUser++)
      cout << "\t" << users[idUser].name << endl;
}
   
/****************************************************
 * INTERACT :: PROMPT FOR LINE
 * prompt for a line of input
 ****************************************************/
string Interact::promptForLine(const char * verb) const
{
   string line;
   cout << "Please provide a " << verb << ": ";
   getline(cin, line);
   return line;
}

/****************************************************
 * INTERACT :: PROMPT FOR ID
 * prompt for a message ID
 ***************************************************/
int Interact::promptForId(const char * verb) const
{
   string id;
   cout << "Select the message ID to " << verb << ": ";
   cin  >> id;
   cin.ignore();
   return atoi(id.c_str());
}

/****************************************************
 * INTERACT :: AUTHENTICATION
 * authenticate the user: find their control level
 ****************************************************/
Control Interact::authenticate(const string & userName,
                            const string & password) const
{
   int id = idFromUser(userName);
   ControlMap controlMap;

   //If username and password are not recognized, assume the lowest level
   Control subjectControl = controlMap.getLowestLevel();
   if (ID_INVALID != id && password == string(users[id].password))
      subjectControl = users[id].subjectControl;
   return subjectControl;
}

/****************************************************
 * INTERACT :: ID FROM USER
 * Find the ID of a given user
 ****************************************************/
int Interact::idFromUser(const string & userName) const
{
   for (int idUser = 0; idUser < sizeof(users) / sizeof(users[0]); idUser++)
      if (userName == string(users[idUser].name))
         return idUser;
   return ID_INVALID;
}