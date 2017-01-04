class StaticFilesMiddleware : public ApplicationBuilder
{
  private:
  public:
    StaticFilesMiddleware();
    ~StaticFilesMiddleware();

  void OnMessage(HTTPContext* context);
};