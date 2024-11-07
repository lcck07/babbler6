#include "babbler6App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
babbler6App::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

babbler6App::babbler6App(InputParameters parameters) : MooseApp(parameters)
{
  babbler6App::registerAll(_factory, _action_factory, _syntax);
}

babbler6App::~babbler6App() {}

void
babbler6App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<babbler6App>(f, af, s);
  Registry::registerObjectsTo(f, {"babbler6App"});
  Registry::registerActionsTo(af, {"babbler6App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
babbler6App::registerApps()
{
  registerApp(babbler6App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
babbler6App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  babbler6App::registerAll(f, af, s);
}
extern "C" void
babbler6App__registerApps()
{
  babbler6App::registerApps();
}
