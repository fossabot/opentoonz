#pragma once

#ifndef MODIFIERTANGENTS_INCLUDED
#define MODIFIERTANGENTS_INCLUDED

// TnzTools includes
#include <tools/inputmanager.h>

#undef DVAPI
#undef DVVAR
#ifdef TNZTOOLS_EXPORTS
#define DVAPI DV_EXPORT_API
#define DVVAR DV_EXPORT_VAR
#else
#define DVAPI DV_IMPORT_API
#define DVVAR DV_IMPORT_VAR
#endif

//===================================================================

//*****************************************************************************************
//    TModifierTangents definition
//*****************************************************************************************

class DVAPI TModifierTangents : public TInputModifier {
public:
  typedef TSubTrackHandler Handler;
  class DVAPI Interpolator : public TTrackInterpolator {
  public:
    TTrackTangentList tangents;
    using TTrackInterpolator::TTrackInterpolator;
    TTrackPoint interpolate(double index) override;
  };

  static TTrackTangent calcTangent(const TTrack &track, int index);

  void modifyTrack(const TTrack &track, TTrackList &outTracks) override;
};

#endif
