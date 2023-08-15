# Zarya

[![MIT licensed](https://img.shields.io/badge/license-MIT-blue.svg)](https://gitlab.aiursoft.cn/aiursoft/infrastructures/-/blob/master/LICENSE)
[![Pipeline stat](https://gitlab.aiursoft.cn/anduin/zarya/badges/master/pipeline.svg)](https://gitlab.aiursoft.cn/anduin/zarya/-/pipelines)

Usage: After starting Zarya, it will serve as a web application with the wwwroot directory as the root directory and port 8080 as the port number.

## Why this project is no longer maintained

While maintaining Zarya, I suddenly realized that there are too many details to handle when building a web server...

Middleware, caching, dependency injection, resumable downloads, ETags, cookies, context discovery and response rendering, performance, filters, protectors...

For friends who are interested in Zarya, it is not complete, with only basic static file hosting capabilities. If you are willing to extend it, please take this code with you.

## How to run

Environment required for running:  

* Linux Or Unix (not supported on Windows)  

Installation required before running:

* git
* g++

Commands required to start the project:

```bash
mkdir Bin &> /dev/null
g++ ./Program.cpp -o Bin/Program.out
./Bin/Program.out
```

Then start your browser and visit the following URL:

>http://localhost:9000/

If you can experience the application normally, congratulations, you have completed the compilation, linking and running of this project!
