#pragma once

#include "AnimateSDK/app/DOM/Utils/DOMTypes.h"
#include "Segment.h"

namespace sc
{
	namespace Adobe
	{
		class FilledElementPathQuadSegment : public FilledElementPathSegment
		{
		public:
			FilledElementPathQuadSegment(const DOM::Utils::SEGMENT& segment);

		public:
			virtual FilledElementPathSegment::Type SegmentType() const {
				return FilledElementPathSegment::Type::Cubic;
			};

			virtual Point2D Rasterize(float t_step) const;

			virtual float IterationStep() const;

			virtual void Transform(const DOM::Utils::MATRIX2D& matrix);

		public:
			Point2D begin;
			Point2D control;
			Point2D end;
		};
	}
}