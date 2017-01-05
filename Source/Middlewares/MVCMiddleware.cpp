MVCMiddleware::MVCMiddleware() {}
MVCMiddleware::~MVCMiddleware() 
{
    delete this->NextMiddleware;
}

void MVCMiddleware::OnMessage(HTTPContext *context)
{
  const char *path = context->Path;
  if (strcmp(path, "./wwwroot/home/index") == 0)
  {
    HomeController *homecontroller = new HomeController();
    homecontroller->Index();
    std::cout << "[200] MVC" << path << std::endl;
    return;
  }
  else if (strcmp(path, "./wwwroot/home/sprites") == 0)
  {
    HomeController *homecontroller = new HomeController();
    homecontroller->Sprites(context);
    std::cout << "[200] MVC" << path << std::endl;
    return;
  }
  else
  {
    this->NextMiddleware->OnMessage(context);
  }
}
