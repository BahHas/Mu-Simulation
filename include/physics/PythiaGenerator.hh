/*
 * include/physics/PythiaGenerator.hh
 *
 * Copyright 2018 Brandon Gomes
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MU__PHYSICS_PYTHIAGENERATOR_HH
#define MU__PHYSICS_PYTHIAGENERATOR_HH
#pragma once

#include <string>
#include <vector>

#include <Pythia8/Pythia.h>
#include <Pythia8/Event.h>

#include "physics/Generator.hh"

namespace MATHUSLA { namespace MU {

namespace Physics { ////////////////////////////////////////////////////////////////////////////

//__Pythia Particle Generator___________________________________________________________________
class PythiaGenerator : public RangeGenerator {
public:
  PythiaGenerator(const int id,
                  const double pT,
                  const double eta,
                  const double phi,
                  Pythia8::Pythia* pythia=nullptr);

  PythiaGenerator(const int id,
                  const double pT,
                  const double eta,
                  const double phi,
                  std::vector<std::string> settings);

  PythiaGenerator(const int id,
                  const double pT_min,
                  const double pT_max,
                  const double eta_min,
                  const double eta_max,
                  const double phi_min,
                  const double phi_max,
                  Pythia8::Pythia* pythia=nullptr);

  PythiaGenerator(const int id,
                  const double pT_min,
                  const double pT_max,
                  const double eta_min,
                  const double eta_max,
                  const double phi_min,
                  const double phi_max,
                  std::vector<std::string> settings);

  void GeneratePrimaryVertex(G4Event* event);
  void SetNewValue(G4UIcommand* command, G4String value);
  void SetPythia(Pythia8::Pythia* pythia);
  void SetPythia(std::vector<std::string> settings);
  Pythia8::Particle* FindParticle(Pythia8::Event& event) const;

  // TODO: virtual const Analysis::SimSettingList GetSpecification() const;
  // TODO: virtual const Analysis::ROOT::DataEntryList GetGenParticleData() const;

private:
  Pythia8::Pythia* _pythia;
  std::vector<std::string> _pythia_settings;
  Command::StringArg* _read_string;
  Command::StringArg* _read_file;
};
//----------------------------------------------------------------------------------------------

} /* namespace Physics */ //////////////////////////////////////////////////////////////////////

} } /* namespace MATHUSLA::MU */

#endif /* MU__PHYSICS_PYTHIAGENERATOR_HH */
