/*
Degree defines the different degree options for a student
*/

#ifndef degree_h
#define degree_h

#pragma once
#include <string>
#include <array>
using namespace std;

enum Degree{SECURITY, NETWORKING, SOFTWARE};
static string stringDegree[] = {"SECURITY", "NETWORKING", "SOFTWARE"};

static Degree stringToDegree(string s)
{
    if ( s == "SECURITY" ) return SECURITY;
    else if ( s == "NETWORK" ) return NETWORKING;
    else return SOFTWARE;
}

static string degreeToString(Degree d)
{
    if ( d == SECURITY ) return "SECURITY";
    else if( d == NETWORKING ) return "NETWORK";
    else return "SOFTWARE";
}

#endif /* degree_h */
