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

#pragma once
#include <map>
/************************************************************************
 * The Control data type 
 * The data structure used to determine confidentiality levels
 * **********************************************************************/
enum Control {
    PUBLIC, CONFIDENTIAL, PRIVILEGED, SECRET
};

/************************************************************************
 * Map the string representation of control level to the Control representation
 * to make it easy to add control levels
 * To add more control levels, add more insert statements to the constructor
 * Also remember to insert the value into the enum above.
 * **********************************************************************/
class ControlMap {
private:
    std::map<std::string, Control> controlMap;
    std::pair<std::string, Control> lowestLevel;
    std::pair<std::string, Control> highestLevel;
public:
    ControlMap() {
        //Add more insert statements to this to include more control levels
        controlMap.insert({"Public", PUBLIC});
        controlMap.insert({"Confidential", CONFIDENTIAL});
        controlMap.insert({"Privileged", PRIVILEGED});
        controlMap.insert({"Secret", SECRET});

        //If the highest or lowest level changes, please also change these:
        this->lowestLevel = {"Public", PUBLIC};
        this->highestLevel = {"Secret", SECRET};
    };

    std::map<Control, std::string> getMap();

    // Return Control type representation of Control given the string
    Control getControlNum(const std::string &controlText);

    // Return string representation of Control
    std::string getControlString(const Control &controlNum);

    // Get the highest control level
    Control getHighestLevel() { return this->highestLevel.second; }

    // Get the lowest control level
    Control getLowestLevel() { return this->lowestLevel.second; }
};

/************************************************************************
 * Security Condition Read prototype
 * Determine if the subject can read the asset given the control
 * levels of the asset and the subject
 * **********************************************************************/
bool securityConditionRead(const Control &assetControl, const Control &subjectControl);

/************************************************************************
 * Security Condition Write prototype
 * Determine if the subject can write to the asset given the control
 * levels of the asset and the subject
 * **********************************************************************/
bool securityConditionWrite(const Control &assetControl, const Control &subjectControl);