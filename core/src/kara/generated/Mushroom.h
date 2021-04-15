/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_MUSHROOM_H
#define DE_UNISTUTTGART_KARA_MUSHROOM_H

#include <memory>
#include <string>
#include "Prop.h"

namespace kara {

class Mushroom: public mpw::Prop {

private:

	using inherited = Prop;

public:

	Mushroom();

	/// \brief returns a shared_ptr of type Mushroom which shares ownership of *this
	std::shared_ptr<Mushroom> shared_from_this() {
		return std::dynamic_pointer_cast < Mushroom
				> (inherited::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type Mushroom which shares ownership of *this
	std::shared_ptr<const Mushroom> shared_from_this() const {
		return std::dynamic_pointer_cast<const Mushroom>(
				inherited::shared_from_this());
	}

public:

	virtual ~Mushroom() = default;

	using Prop::cFeatureKeyCurrentTile;
	using Prop::cFeatureKeyStage;

	void setProperty(unsigned featureKey, Any value) override;
	void addToCollection(unsigned featureKey, EntityReference reference)
			override;
	void removeFromCollection(unsigned featureKey, EntityReference reference)
			override;

};

}

#endif //DE_UNISTUTTGART_KARA_MUSHROOM_H

