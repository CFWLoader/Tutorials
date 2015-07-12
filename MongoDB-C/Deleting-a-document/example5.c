#include <bson.h>
#include <mongoc.h>
#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
    mongoc_client_t *client;
    mongoc_collection_t *collection;
    mongoc_cursor_t *cursor;
    bson_error_t error;
    bson_oid_t oid;
    bson_t *doc;

    mongoc_init ();

    client = mongoc_client_new ("mongodb://evan:123456@192.168.0.112:27017/");
    collection = mongoc_client_get_collection (client, "test", "test");

    doc = bson_new ();
    bson_oid_init (&oid, NULL);
    BSON_APPEND_OID (doc, "_id", &oid);
    BSON_APPEND_UTF8 (doc, "hello", "world");

    if (!mongoc_collection_insert (collection, MONGOC_INSERT_NONE, doc, NULL, &error)) {
        printf ("Insert failed: %s\n", error.message);
    }

    bson_destroy (doc);

    doc = bson_new ();
    BSON_APPEND_OID (doc, "_id", &oid);

    printf("The mongo db has a new record now and you should check it.\n"
        "Confirm the Insertion and press any key to continue the delete operation.\n"
        "You will see the record is removed.\n");
    getc(stdin);

    if (!mongoc_collection_remove (collection, MONGOC_DELETE_SINGLE_REMOVE, doc, NULL, &error)) {
        printf ("Delete failed: %s\n", error.message);
    }

    bson_destroy (doc);
    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);

    return 0;
}