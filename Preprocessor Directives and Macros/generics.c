/*
This file is meant only to demonstrate how C generics can be useful in certain usecases when the
type set you are dealing with is bounded. JSON works perfectly here because json can, 
for the most part, only have 7 types: bool, int, float, string, array, JSON, NULL. 

We will skip arrays for the sake of brevity, however for a full implementation of a 
json parser/creator/formater that has this same API and usage of generics
visit: https://github.com/superg3m/cj.git

This file is meant to be an exersise not just in generics but also good API design.
As a developer you want to interact with tools and libraries that lets you express
exactly what you want in the least amount of time. So contribute to that ethos by making
tools and libraries that you genuinely want to use. Good API design is pretty hard and not always
feasible, but in practice there should be a granular API and a simplifed API. The simplified API is
a wrapper around the complexity of the granualar API geared towards the most common usage patterns.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define stringify(entry) #entry

typedef enum JSONType {
    JSON_TYPE_BOOL,
    JSON_TYPE_INT,
    JSON_TYPE_FLOAT,
    JSON_TYPE_STRING,
    // JSON_TYPE_ARRAY,
    JSON_TYPE_JSON,
    JSON_TYPE_NULL,
} JSONType;

const char* json_type_strings[] = {
    stringify(JSON_TYPE_BOOL),
    stringify(JSON_TYPE_INT),
    stringify(JSON_TYPE_FLOAT),
    stringify(JSON_TYPE_STRING),
    // stringify(JSON_TYPE_ARRAY),
    stringify(JSON_TYPE_JSON),
    stringify(JSON_TYPE_NULL)
};

typedef struct JSON {
    JSONType type;
} JSON;

JSON* json_create() {
    JSON* ret = malloc(sizeof(JSON));
    ret->type = JSON_TYPE_JSON;

    return ret;
}

void private_json_push(JSON* root, char* key, JSON* value) {
    assert(root->type == JSON_TYPE_JSON);

    printf("JSON | %s: %s\n", key, json_type_strings[value->type]);
}

JSON* JSON_INT(int value) {
    JSON* ret = json_create();
    ret->type = JSON_TYPE_INT;

    return ret;
}

JSON* JSON_FLOAT(double value) {
    JSON* ret = json_create();
    ret->type = JSON_TYPE_FLOAT;

    return ret;
}

JSON* JSON_STRING(char* value) {
    JSON* ret = json_create();
    ret->type = JSON_TYPE_STRING;

    return ret;
}

JSON* JSON_BOOL(bool value) {
    JSON* ret = json_create();
    ret->type = JSON_TYPE_BOOL;

    return ret;
}

JSON* JSON_JSON(JSON* json) {
    return json;
}

JSON* JSON_NULL() {
    JSON* ret = json_create();
    ret->type = JSON_TYPE_NULL;

    return ret;
}

// _Generic takes a value and can 'switch' on the type at compile time
#define json_push(root, key, value) private_json_push(root, key, _Generic((value),  \
    bool: JSON_BOOL,                        \
    char*: JSON_STRING,                     \
    const char*: JSON_STRING,               \
    float: JSON_FLOAT,                      \
    double: JSON_FLOAT,                     \
    int: JSON_INT,                          \
    JSON*: JSON_JSON                        \
)(value))

int main() {
    JSON* root = json_create();
    json_push(root, "t1", 1);
    json_push(root, "t2", (bool)true); // This is a unfortunate case but you have to cast to bool here
    json_push(root, "t3", "hello world");
    json_push(root, "t3", 533.24f);
    json_push(root, "t4", 123.67004);

    printf("\n");

    JSON* nested = json_create();
    json_push(nested, "n1", 4042);
    json_push(nested, "n2", (bool)false); // This is a unfortunate case but you have to cast to bool here
    char str[] = "anything here";
    json_push(nested, "n3", str);
    json_push(nested, "n4", JSON_NULL()); // This is another unfortunate case but its not too bad

    printf("\n");

    json_push(root, "t5", nested);

    return 0;
}

/* Ouput:              
JSON | t1: JSON_TYPE_INT
JSON | t2: JSON_TYPE_BOOL
JSON | t3: JSON_TYPE_STRING
JSON | t3: JSON_TYPE_FLOAT
JSON | t4: JSON_TYPE_FLOAT

JSON | n1: JSON_TYPE_INT
JSON | n2: JSON_TYPE_BOOL
JSON | n3: JSON_TYPE_STRING
JSON | n4: JSON_TYPE_NULL

JSON | t5: JSON_TYPE_JSON
*/