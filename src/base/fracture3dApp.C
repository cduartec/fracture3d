#include "fracture3dApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
fracture3dApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

fracture3dApp::fracture3dApp(InputParameters parameters) : MooseApp(parameters)
{
  fracture3dApp::registerAll(_factory, _action_factory, _syntax);
}

fracture3dApp::~fracture3dApp() {}

void
fracture3dApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"fracture3dApp"});
  Registry::registerActionsTo(af, {"fracture3dApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
fracture3dApp::registerApps()
{
  registerApp(fracture3dApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
fracture3dApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  fracture3dApp::registerAll(f, af, s);
}
extern "C" void
fracture3dApp__registerApps()
{
  fracture3dApp::registerApps();
}
