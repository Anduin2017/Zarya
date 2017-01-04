ActionResult::ActionResult(char* ResponseMessage)
{
    this->_result = ResponseMessage;
}
ActionResult::~ActionResult()
{
}

char* ActionResult::GetResult()
{
    return this->_result;
}
void ActionResult::SetResult(char* result)
{
    this->_result = result;
}