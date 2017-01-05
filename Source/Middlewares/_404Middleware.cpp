_404Middleware::_404Middleware() {}
_404Middleware::~_404Middleware()
{
  delete this->NextMiddleware;
}

void _404Middleware::OnMessage(HTTPContext *context)
{
  //FILE *fpsock;
  FILE *fpsock = context->fp;
  fprintf(fpsock, "HTTP/1.1 404 NotFound\r\n");
  fprintf(fpsock, "Content-type: text/plain\r\n");
  fprintf(fpsock, "\r\n");
  fprintf(fpsock, "not found");
  fclose(fpsock);
  std::cout << "[404]" << context->Path << std::endl;
  return;
}
