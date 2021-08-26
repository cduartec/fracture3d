//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "fracture3dTestApp.h"
#include "fracture3dApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
fracture3dTestApp::validParams()
{
  InputParameters params = fracture3dApp::validParams();
  return params;
}

fracture3dTestApp::fracture3dTestApp(InputParameters parameters) : MooseApp(parameters)
{
  fracture3dTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

fracture3dTestApp::~fracture3dTestApp() {}

void
fracture3dTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  fracture3dApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"fracture3dTestApp"});
    Registry::registerActionsTo(af, {"fracture3dTestApp"});
  }
}

void
fracture3dTestApp::registerApps()
{
  registerApp(fracture3dApp);
  registerApp(fracture3dTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
fracture3dTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  fracture3dTestApp::registerAll(f, af, s);
}
extern "C" void
fracture3dTestApp__registerApps()
{
  fracture3dTestApp::registerApps();
}
