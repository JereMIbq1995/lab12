/***********************************************************************
 * COMPONENT:
 *    CONTROL
 * Author:
 *    Jeremy Duong
 * Summary:
 *    This class stores the notion of Bell-LaPadula
 ************************************************************************/

#include "control.h"
using namespace std; //I don't like this but to conform with everything else..

/************************************************************************
 * Security Condition Read implementation
 * Determine if the subject can read the asset given the control
 * levels of the asset and the subject
 * **********************************************************************/
bool securityConditionRead(const Control &assetControl, 
                           const Control &subjectControl)
{
    return subjectControl >= assetControl; //Read: down allowed, up restricted
}

/************************************************************************
 * Security Condition Write implementation
 * Determine if the subject can write to the asset given the control
 * levels of the asset and the subject
 * **********************************************************************/
bool securityConditionWrite(const Control &assetControl, 
                           const Control &subjectControl)
{
    return subjectControl <= assetControl; //Write: down restricted, up allowed
}

/************************************************************************
 * Return Control type representation of Control given the string
 * **********************************************************************/
Control ControlMap::getControlNum(const std::string &controlText) 
{ 
    return this->controlMap[controlText];
}

/************************************************************************
 * Return Control type representation of Control given the string
 * **********************************************************************/
std::string ControlMap::getControlString(const Control &controlNum) 
{
    for (auto const& keyValuePair : this->controlMap) {
        if (keyValuePair.second == controlNum)
        {
            return keyValuePair.first;
        }
    }
    return NULL;
}