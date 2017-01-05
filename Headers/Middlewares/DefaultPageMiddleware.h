class DefaultPageMiddleware : public ApplicationBuilder
{
  private:
  public:
    DefaultPageMiddleware();
    ~DefaultPageMiddleware();

  void OnMessage(HTTPContext* context);
};