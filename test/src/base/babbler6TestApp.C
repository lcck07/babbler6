//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "babbler6TestApp.h"
#include "babbler6App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
babbler6TestApp::validParams()
{
  InputParameters params = babbler6App::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

babbler6TestApp::babbler6TestApp(InputParameters parameters) : MooseApp(parameters)
{
  babbler6TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

babbler6TestApp::~babbler6TestApp() {}

void
babbler6TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  babbler6App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"babbler6TestApp"});
    Registry::registerActionsTo(af, {"babbler6TestApp"});
  }
}

void
babbler6TestApp::registerApps()
{
  registerApp(babbler6App);
  registerApp(babbler6TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
babbler6TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  babbler6TestApp::registerAll(f, af, s);
}
extern "C" void
babbler6TestApp__registerApps()
{
  babbler6TestApp::registerApps();
}
