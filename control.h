/***********************************************************************
 * COMPONENT:
 *    CONTROL
 * Author:
 *    Jeremy Duong
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
 * **********************************************************************/
class ControlMap {
private:
    std::map<std::string, Control> controlMap;
public:
    ControlMap() {
        controlMap.insert({"Public", PUBLIC});
        controlMap.insert({"Confidential", CONFIDENTIAL});
        controlMap.insert({"Privileged", PRIVILEGED});
        controlMap.insert({"Secret", SECRET});
    };

    std::map<Control, std::string> getMap();

    // Return Control type representation of Control given the string
    Control getControlNum(const std::string &controlText);

    // Return string representation of Control
    std::string getControlString(const Control &controlNum);
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