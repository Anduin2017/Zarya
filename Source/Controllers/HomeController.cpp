class Controller
{
};

class HomeController : public Controller
{
  public:
    IActionResult *Index()
    {
        return 0;
    }

    IActionResult *Sprites(HTTPContext *context)
    {
        FILE *fp = context->fp;
        fprintf(fp, "HTTP/1.1 200 OK\r\n");
        fprintf(fp, "Content-type: application/json; charset=utf-8\r\n");
        fprintf(fp, "\r\n");
        fprintf(fp, "{\"ship\":{\"sx\":0,\"sy\":0,\"w\":37,\"h\":42,\"frames\":1},\"missile\":{\"sx\":0,\"sy\":30,\"w\":2,\"h\":10,\"frames\":1},\"enemy_purple\":{\"sx\":37,\"sy\":0,\"w\":42,\"h\":43,\"frames\":1},\"enemy_bee\":{\"sx\":79,\"sy\":0,\"w\":37,\"h\":43,\"frames\":1},\"enemy_ship\":{\"sx\":116,\"sy\":0,\"w\":42,\"h\":43,\"frames\":1},\"enemy_circle\":{\"sx\":158,\"sy\":0,\"w\":32,\"h\":33,\"frames\":1},\"explosion\":{\"sx\":0,\"sy\":64,\"w\":64,\"h\":64,\"frames\":12}}");
        fclose(fp);
        return 0;
    }
};