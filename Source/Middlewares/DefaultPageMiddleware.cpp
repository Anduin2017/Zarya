DefaultPageMiddleware::DefaultPageMiddleware() {}
DefaultPageMiddleware::~DefaultPageMiddleware()
{
  delete this->NextMiddleware;
}

void DefaultPageMiddleware::OnMessage(HTTPContext *context)
{
  if (strcmp(context->Path, "./wwwroot/") == 0)
  {
    context->Path = "./wwwroot/index.html";
  }
  this->NextMiddleware->OnMessage(context);
}
