#include "JSONNode.h"

void JSONNode::parse(char const *text){
	root = cJSON_Parse(text);
}
// name ==> index
cJSON *JSONNode::getObjectItem(cJSON *head, char *name)
{
	return cJSON_GetObjectItem(head,name);
}
// i ==>index
cJSON *JSONNode::getArrayItem(cJSON *head, int index)
{
	if(index >= getArraySize(head)) return NULL;
	return cJSON_GetArrayItem(head, index);
}

cJSON *JSONNode::spawnNode(int nodeType, char *name)
{
	cJSON *node = NULL;
	if(nodeType == cJSON_Object) {
		node = cJSON_CreateObject();
		node -> string = name;
	}else if(nodeType == cJSON_Array){
		node = cJSON_CreateArray();
		node -> string = name;
	}else if(nodeType == cJSON_True){
		node = cJSON_CreateTrue();
		node -> string = name;
	}else if(nodeType == cJSON_False){
		node = cJSON_CreateFalse();
		node -> string = name;
	}else if(nodeType == cJSON_NULL){
		node = cJSON_CreateNull();
		node -> string = name;
	}
	
	return  node;
}

// string type "name" : "value"
cJSON *JSONNode::spawnNode(int nodeType, char const *value, char *name)
{	
	cJSON *node = NULL;
	if(nodeType == cJSON_String)
	{
		node = cJSON_CreateString(value);
		node->string = name;
	} 
	
	return node;
}

// number type
cJSON *JSONNode::spawnNode(int nodeType, double value, char *name)
{
	cJSON *node = NULL;
	if(nodeType == cJSON_Number)
	{
		node = cJSON_CreateNumber(value);
		node->string = name;
	}

	return node;
}

void JSONNode::addItemToNode(cJSON *head, int nodeType, cJSON *item)
{
	if (nodeType == cJSON_Object || nodeType == cJSON_Array)
	{
		cJSON_AddItemToArray(head, item);
	}
}

char const *JSONNode::errorMessage()
{
	return cJSON_GetErrorPtr();
}

char const *JSONNode::dump()
{
	return cJSON_Print(root);	
}
