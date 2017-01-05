StaticFilesMiddleware::StaticFilesMiddleware() {}
StaticFilesMiddleware::~StaticFilesMiddleware() 
{
  delete this->NextMiddleware;
}

void header(FILE *fp,const char *content_type)
{
  fprintf(fp, "HTTP/1.0 200 OK\r\n");
  if (content_type)
    fprintf(fp, "Content-type: %s\r\n", content_type);
}

const char *rmask(const char *string)
{
  char *p = new char[BUFSIZ];
  strcpy(p,string);
  if (p == NULL)
  {
    return NULL;
  }
  else
  {
    int i = 0;
    while (*p != '\0' && *p != '?')
    {
      i++;
      p++;
    }
    *(p++) = '\0';
    return string;
  }
}

const char *file_type(const char *f)
{
  const char *cp;
  if ((cp = strrchr(f, '.')) != NULL)
    return cp + 1;
  return "";
}

void StaticFilesMiddleware::OnMessage(HTTPContext *context)
{
  const char *extension = file_type(context->Path);
  const char *content = "text/plain";
  FILE *fpsock, *fpfile;
  int c;

  if (strcmp(extension, "html") == 0)
    content = "text/html";
  else if (strcmp(extension, "css") == 0)
    content = "text/css";
  else if (strcmp(extension, "gif") == 0)
    content = "image/gif";
  else if (strcmp(extension, "png") == 0)
    content = "image/png";
  else if (strcmp(extension, "jpg") == 0)
    content = "image/jpeg";
  else if (strcmp(extension, "jpeg") == 0)
    content = "image/jpeg";
  else if (strcmp(extension, "js") == 0)
    content = "application/x-javascript";
  else if (strcmp(extension, "ico") == 0)
    content = "image/ico";
  else if (strcmp(extension, "svg") == 0)
    content = "image/svg+xml";
  else if (strcmp(extension, "json") == 0)
    content = "application/json";

  //fpsock = fdopen(fd, "w");
  fpsock = context->fp;
  const char *path = rmask(context->Path);
  fpfile = fopen(path, "r");
  if (fpsock != NULL && fpfile != NULL)
  {
    header(fpsock, content);
    fprintf(fpsock, "\r\n");
    while ((c = getc(fpfile)) != EOF)
      putc(c, fpsock);
    fclose(fpfile);
    fclose(fpsock);
    std::cout << "[200]" << path << std::endl;
    return;
  }
  else
  {
    this->NextMiddleware->OnMessage(context);
  }
}
