//#pragma GCC diagnostic ignored "-Wwrite-strings". 

#define interface class
#define implements public

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <pthread.h>


#include "Librarys/socketlib.c"
//.h
#include "Models/HTTPContext.h"
#include "Interfaces/IActionResult.h"
#include "Interfaces/IApplicationBuilder.h"
#include "Interfaces/IApplicationServer.h"
#include "Interfaces/IService.h"
#include "Models/ApplicationBuilder.h"
#include "Middlewares/_404Middleware.h"
#include "Middlewares/StaticFilesMiddleware.h"
#include "Middlewares/MVCMiddleware.h"
#include "Middlewares/DefaultPageMiddleware.h"
#include "Models/ActionResult.h"
#include "Models/HostBuilder.h"
#include "Models/StartUp.h"
#include "Models/SombraServer.h"
//Controller
#include "../Source/Controllers/HomeController.cpp"

//.cpp
#include "../Source/Models/HTTPContext.cpp"
#include "../Source/Models/ActionResult.cpp"
#include "../Source/Models/HostBuilder.cpp"
#include "../Source/StartUp.cpp"
#include "../Source/Models/SombraServer.cpp"
#include "../Source/Models/ApplicationBuilder.cpp"
#include "../Source/Middlewares/_404Middleware.cpp"
#include "../Source/Middlewares/StaticFilesMiddleware.cpp"
#include "../Source/Middlewares/MVCMiddleware.cpp"
#include "../Source/Middlewares/DefaultPageMiddleware.cpp"


