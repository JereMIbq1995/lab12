/***********************************************************************
 * COMPONENT:
 *    CONTROL
 * Author:
 *    Jeremy Duong
 *    Austin Lundberg
 *    Timothy Stephenson
 *    Gabriel Sanahuano
 *    Sophia Pearson
 *    David Headrick
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
    for (auto keyValuePair : this->controlMap)
    {
        if (keyValuePair.first == controlText)
        {
            return this->controlMap[controlText];
        }
    }
    //If control text is not recognize, assume it's the highest level
    return this->highestLevel.second;
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
    //If ControlNum is not recognized in the map, assume it's the highest level
    return this->highestLevel.first;
}