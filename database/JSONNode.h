

#ifndef JSON_PARSER_MUMAN_H
#define JSON_PARSER_MUMAN_H

#include "cJSON.h"
#include <iostream>

using namespace std;

/***************************************************
 Make The Json Query API as a Programming Language
	{
		"name": "han",
		"age": 26,
		"skils": [ "C++", "C", "Linux", "Data Warehouse"]
	}
API:
	Only one root TYPE ==> Object
			  		   ==> Array

Type:
	 #define cJSON_False 0
	 #define cJSON_True 1
	 #define cJSON_NULL 2
	 #define cJSON_Number 3
	 #define cJSON_String 4
	 #define cJSON_Array 5
	 #define cJSON_Object 6

 ***************************************************/
#define tFALSE cJSON_False
#define tTRUE cJSON_True
#define tNULL cJSON_NULL
#define tNUMBER cJSON_Number
#define tSTRING cJSON_String
#define tARRAY cJSON_Array
#define tOBJECT cJSON_Object

class JSONNode
{
public:
	//typedef cJSON *NodePtr;

	JSONNode(int nType):root(NULL),nodeType(nType) { root = spawnNode(nodeType, NULL);} // a brandnew base node[ object or array]
	JSONNode():root(NULL) { } // a parser
	~JSONNode(){
		if (root != NULL) 
			cJSON_Delete(root);
	}
	void parse(char const *text);
	
	// NULL? - Query 
	cJSON *getObjectItem(cJSON *head, char *name);
	cJSON *getArrayItem(cJSON *head, int index);
	int getArraySize(cJSON *head);

	//       - Log
	cJSON *spawnNode(int nodeType, char *name);
	cJSON *spawnNode(int nodeType, char const *value, char *name);
	cJSON *spawnNode(int nodeType, double value, char *name);
	void addItemToNode(cJSON *head, int nodeType, cJSON *item);
	
	char const *dump();

	char const *errorMessage();

private:
	cJSON *root;
	int nodeType;
};



#endif


