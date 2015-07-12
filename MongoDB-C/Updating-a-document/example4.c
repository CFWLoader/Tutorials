#include <bcon.h>
#include <bson.h>
#include <mongoc.h>
#include <stdio.h>

int
main (int   argc,
      char *argv[])
{
    mongoc_collection_t *collection;
    mongoc_client_t *client;
    bson_error_t error;
    bson_oid_t oid;
    bson_t *doc = NULL;
    bson_t *update = NULL;
    bson_t *query = NULL;

    mongoc_init ();

    client = mongoc_client_new ("mongodb://evan:123456@192.168.0.112:27017/");
    collection = mongoc_client_get_collection (client, "test", "test");

    bson_oid_init (&oid, NULL);
    doc = BCON_NEW ("_id", BCON_OID (&oid),
                    "hello", BCON_UTF8 ("world!"));

    if (!mongoc_collection_insert (collection, MONGOC_INSERT_NONE, doc, NULL, &error)) {
        printf ("%s\n", error.message);
        goto fail;
    }

    query = BCON_NEW ("_id", BCON_OID (&oid));
    update = BCON_NEW ("$set", "{",
                           "hello", BCON_UTF8 ("Everybody!"),
                           "updated", BCON_BOOL (true),
                       "}");

    if (!mongoc_collection_update (collection, MONGOC_UPDATE_NONE, query, update, NULL, &error)) {
        printf ("%s\n", error.message);
        goto fail;
    }

fail:
    if (doc)
        bson_destroy (doc);
    if (query)
        bson_destroy (query);
    if (update)
        bson_destroy (update);

    mongoc_collection_destroy (collection);
    mongoc_client_destroy (client);

    return 0;
}