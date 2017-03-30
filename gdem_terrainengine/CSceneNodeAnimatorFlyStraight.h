// Copyright (C) 2002-2008 Nikolaus Gebhardt
// This file is part of the "Geo Engine".
// For conditions of distribution and use, see copyright notice in geoEngine.h

#ifndef __C_SCENE_NODE_ANIMATOR_FLY_STRAIGHT_H_INCLUDED__
#define __C_SCENE_NODE_ANIMATOR_FLY_STRAIGHT_H_INCLUDED__

#include "ISceneNode.h"

namespace geo
{
namespace scene
{
	class CSceneNodeAnimatorFlyStraight : public ISceneNodeAnimator
	{
	public:

		//! constructor
		CSceneNodeAnimatorFlyStraight(const core::vector3df& startPoint,
						const core::vector3df& endPoint,
						u32 timeForWay,
						bool loop, u32 now);

		//! destructor
		virtual ~CSceneNodeAnimatorFlyStraight();

		//! animates a scene node
		virtual void animateNode(ISceneNode* node, u32 timeMs);

		//! Writes attributes of the scene node animator.
		virtual void serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options=0) const;

		//! Reads attributes of the scene node animator.
		virtual void deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options=0);

		//! Returns type of the scene node animator
		virtual ESCENE_NODE_ANIMATOR_TYPE getType() const { return ESNAT_FLY_STRAIGHT; }
		
		//! Creates a clone of this animator.
		/** Please note that you will have to drop
		(IReferenceCounted::drop()) the returned pointer after calling
		this. */
		virtual ISceneNodeAnimator* createClone(ISceneNode* node, ISceneManager* newManager=0);

	private:

		void recalculateImidiateValues();

		core::vector3df Start;
		core::vector3df End;
		core::vector3df Vector;
		f32 WayLength;
		f32 TimeFactor;
		u32 StartTime;
		u32 TimeForWay;
		bool Loop;
	};


} // end namespace scene
} // end namespace geo

#endif

