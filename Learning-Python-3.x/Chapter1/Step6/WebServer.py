__author__ = 'cfwloader'
"""
This is a simple http server constructed by python. It's only 8 lines.
It can automatically run python scripts to reponse to a request in the specified directory
if system configured correctly.
"""

import os, sys
from http.server import HTTPServer, CGIHTTPRequestHandler

webDir = '.'

port = 80

os.chdir(webDir)

serverAddress = ("", port)
serverObject = HTTPServer(serverAddress, CGIHTTPRequestHandler)

serverObject.serve_forever()