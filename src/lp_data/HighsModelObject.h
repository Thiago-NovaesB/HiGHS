/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                       */
/*    This file is part of the HiGHS linear optimization suite           */
/*                                                                       */
/*    Written and engineered 2008-2021 at the University of Edinburgh    */
/*                                                                       */
/*    Available as open-source under the MIT License                     */
/*                                                                       */
/*    Authors: Julian Hall, Ivet Galabova, Qi Huangfu, Leona Gottwald    */
/*    and Michael Feldmeier                                              */
/*                                                                       */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef LP_DATA_HIGHS_MODEL_OBJECT_H_
#define LP_DATA_HIGHS_MODEL_OBJECT_H_

#include "HConfig.h"
#include "lp_data/HStruct.h"
#include "lp_data/HighsLp.h"
#include "lp_data/HighsOptions.h"
#include "simplex/HEkk.h"
#include "simplex/HFactor.h"
#include "simplex/HMatrix.h"
#include "simplex/HighsSimplexAnalysis.h"
#include "simplex/SimplexStruct.h"
#include "util/HighsRandom.h"
#include "util/HighsTimer.h"

// Class to communicate data between the simplex solver and the class
// Highs below. Sensitivity data structure would be added here. Only
// include essential data.
class HighsModelObject {
 public:
  HighsModelObject(const HighsLp& lp, HighsSolution& solution,
                   HighsBasis& basis, HighsIterationCounts& iteration_counts,
                   HighsOptions& options, HighsTimer& timer)
      : lp_(lp),
        solution_(solution),
        basis_(basis),
        iteration_counts_(iteration_counts),
        options_(options),
        timer_(timer),
        ekk_instance_(options, timer) {}

  const HighsLp& lp_;
  HighsSolution& solution_;
  HighsBasis& basis_;
  HighsIterationCounts& iteration_counts_;
  HighsOptions& options_;
  HighsTimer& timer_;

  HighsModelStatus unscaled_model_status_ = HighsModelStatus::kNotset;
  HighsModelStatus scaled_model_status_ = HighsModelStatus::kNotset;

  HighsSolutionParams solution_params_;

  HighsScale scale_;
  HEkk ekk_instance_;
};

#endif  // LP_DATA_HIGHS_MODEL_OBJECT_H_
