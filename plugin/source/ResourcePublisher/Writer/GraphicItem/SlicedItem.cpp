#include "ResourcePublisher/Writer/GraphicItem/SlicedItem.h"

namespace sc
{
	namespace Adobe
	{
		SlicedItem::SlicedItem(Ref<cv::Mat> image, const DOM::Utils::MATRIX2D& matrix, const DOM::Utils::RECT guides) :
			SpriteItem(image, matrix),
			m_guides(
				std::ceil(guides.bottomRight.x),
				std::ceil(guides.bottomRight.y),
				std::ceil(guides.topLeft.x),
				std::ceil(guides.topLeft.y)
			)
		{
			// Right & Bottom must be always negative
			// But sometimes Animate (user) breaks this rule
			// So just swipe it if need
			bool is_bottom_swiped = guides.bottomRight.x < 0.0f || guides.topLeft.x >= 0.0f;
			bool is_right_swiped = guides.bottomRight.y < 0.0 || guides.topLeft.y >= 0.0f;

			m_guides.top = std::ceil(is_bottom_swiped ? guides.topLeft.x : guides.bottomRight.x);
			m_guides.left = std::ceil(is_right_swiped ? guides.topLeft.y : guides.bottomRight.y);
			m_guides.bottom = std::ceil(is_bottom_swiped ? guides.bottomRight.x : guides.topLeft.x);
			m_guides.right = std::ceil(is_right_swiped ? guides.bottomRight.y : guides.topLeft.y);
		}
	}
}