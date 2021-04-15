/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_LEAF_H
#define DE_UNISTUTTGART_KARA_LEAF_H

#include <memory>
#include <string>
#include "Prop.h"

namespace kara {

class Leaf: public mpw::Prop {

private:

	using inherited = Prop;

public:

	Leaf();

	/// \brief returns a shared_ptr of type Leaf which shares ownership of *this
	std::shared_ptr<Leaf> shared_from_this() {
		return std::dynamic_pointer_cast < Leaf
				> (inherited::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type Leaf which shares ownership of *this
	std::shared_ptr<const Leaf> shared_from_this() const {
		return std::dynamic_pointer_cast<const Leaf>(
				inherited::shared_from_this());
	}

public:

	virtual ~Leaf() = default;

	using Prop::cFeatureKeyCurrentTile;
	using Prop::cFeatureKeyStage;

	void setProperty(unsigned featureKey, Any value) override;
	void addToCollection(unsigned featureKey, EntityReference reference)
			override;
	void removeFromCollection(unsigned featureKey, EntityReference reference)
			override;

};

}

#endif //DE_UNISTUTTGART_KARA_LEAF_H

