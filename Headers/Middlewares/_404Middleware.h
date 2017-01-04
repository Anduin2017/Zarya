class _404Middleware : public ApplicationBuilder
{
  private:
  public:
    _404Middleware();
    ~_404Middleware();

  void OnMessage(HTTPContext* context);
};