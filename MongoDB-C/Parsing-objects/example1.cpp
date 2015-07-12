#include <bson.h>
#include <mongoc.h>
#include <stdio.h>

#include <json/json.h>

using namespace std;

int parserData(const char*);

int main (int argc,char* argv[])
{
    mongoc_client_t *client;
    mongoc_collection_t *collection;
    mongoc_cursor_t *cursor;

    const bson_t *doc;

    bson_t *query;

    char *str;

    mongoc_init ();

    client = mongoc_client_new ("mongodb://evan:123456@192.168.0.112:27017/");
    collection = mongoc_client_get_collection (client, "clown", "testCollection");
    query = bson_new ();

    BSON_APPEND_UTF8 (query, "arc", "arc");

    cursor = mongoc_collection_find (collection, MONGOC_QUERY_NONE, 0, 0, 0, query, NULL, NULL);

    while (mongoc_cursor_next (cursor, &doc)) {
        str = bson_as_json (doc, NULL);

        parserData(str);

        //cout << "Report code:  " << parserData(str) << endl;
        //printf ("%s\n", str);
        bson_free (str);
    }

    bson_destroy (query);
    mongoc_cursor_destroy (cursor);
    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);

    return 0;
}

int parserData(const char* rawData)
{
    Json::Reader reader;
    Json::Value root;

    if(!reader.parse(rawData, root))return -1;

    string name = root["arc"].asString();

    printf("Name:  %s\n", name.c_str());

    Json::Value subRoot = root["_id"];

    string objectId = subRoot["$oid"].asString();

    printf("Object ID:  %s\n", objectId.c_str());

    return 0;
}