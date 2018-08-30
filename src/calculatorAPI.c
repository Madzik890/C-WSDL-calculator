#include "soap/CalculatorSoap.nsmap"
#include "calculatorAPI.h"

/// <global instance>
const char * g_serviceURL = "http://www.dneonline.com/calculator.asmx?wsdl";
struct soap * g_soap;
/// </global instance>

/// <WSDL commands>
const char * s_additionCommand = "#Add";//+
const char * s_subtractionCommand = "#Subtract";//-
const char * s_multiplyCommand = "#Multiply";//*
const char * s_divideCommand = "#Divide";// \
/// </WSDL commands>

/// <summary>
/// Prepare all objects to start work with the postivo API.
/// </summary>
void startCalculatorAPI()
{
  g_soap = soap_new();//create a new soap instance
  soap_init(g_soap);//init a soap lib
}

/// <summary>
/// Release a memory from the postivo API members.
/// </summary>
void closeCalculatorAPI()
{
  soap_end(g_soap);//end a connection
  soap_destroy(g_soap);//destrony the soap instance
  soap_free(g_soap);//release a memory
}

/// <summary>
/// Additional operation supported by Calculator API.
/// </summary>
/// <param name="firstNumber">The first number of mathematical activity.</param>
/// <param name="firstNumber">The second number of mathematical activity.</param>
/// <returns> Returns the result of adding. </returns>
const int additionOperation(const int firstNumber, const int secondNumber)
{
   struct _tempuri__Add m_addSend;
   struct _tempuri__AddResponse m_addResp;

   m_addSend.intA = firstNumber, m_addSend.intB = secondNumber;

  if(soap_call___tempuri__Add(g_soap, g_serviceURL, s_additionCommand,&m_addSend, &m_addResp) != SOAP_OK)
     soap_print_fault(g_soap, stderr); // display the SOAP fault on the stderr stream

  return m_addResp.AddResult;
}

/// <summary>
/// Subtraction operation supported by Calculator API.
/// </summary>
/// <param name="firstNumber">The first number of mathematical activity.</param>
/// <param name="firstNumber">The second number of mathematical activity.</param>
/// <returns> Returns the result of subtracting. </returns>
const int subtractionOperation(const int firstNumber, const int secondNumber)
{
  struct _tempuri__Subtract m_subSend;
  struct _tempuri__SubtractResponse m_subResp;

  m_subSend.intA = firstNumber, m_subSend.intB = secondNumber;

  if(soap_call___tempuri__Subtract(g_soap, g_serviceURL, s_subtractionCommand, &m_subSend, &m_subResp) != SOAP_OK)
    soap_print_fault(g_soap, stderr); // display the SOAP fault on the stderr stream

  return m_subResp.SubtractResult;
}

/// <summary>
/// Multiply operation supported by Calculator API.
/// </summary>
/// <param name="firstNumber">The first number of mathematical activity.</param>
/// <param name="firstNumber">The second number of mathematical activity.</param>
/// <returns> Returns the result of subtracting. </returns>
const int multiplyOperation(const int firstNumber, const int secondNumber)
{
  struct _tempuri__Multiply m_multiSend;
  struct _tempuri__MultiplyResponse m_multiResp;

  m_multiSend.intA = firstNumber, m_multiSend.intB = secondNumber;

  if(soap_call___tempuri__Multiply(g_soap, g_serviceURL, s_multiplyCommand,&m_multiSend, &m_multiResp) != SOAP_OK)
    soap_print_fault(g_soap, stderr); // display the SOAP fault on the stderr stream

  return m_multiResp.MultiplyResult;
}

/// <summary>
/// Divide operation supported by Calculator API.
/// </summary>
/// <param name="firstNumber">The first number of mathematical activity.</param>
/// <param name="firstNumber">The second number of mathematical activity.</param>
/// <returns> Returns the result of subtracting. </returns>
const int divideOperation(const int firstNumber, const int secondNumber)
{
  struct _tempuri__Divide m_diviSend;
  struct _tempuri__DivideResponse m_diviResp;

  m_diviSend.intA = firstNumber, m_diviSend.intB = secondNumber;

  if(soap_call___tempuri__Divide(g_soap, g_serviceURL, s_divideCommand, &m_diviSend, &m_diviResp) != SOAP_OK)
    soap_print_fault(g_soap, stderr); // display the SOAP fault on the stderr stream

  return m_diviResp.DivideResult;
}
