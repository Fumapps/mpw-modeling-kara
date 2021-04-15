/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_TREE_H
#define DE_UNISTUTTGART_KARA_TREE_H

#include <memory>
#include <string>
#include "Prop.h"

namespace kara {

class Tree: public mpw::Prop {

private:

	using inherited = Prop;

public:

	Tree();

	/// \brief returns a shared_ptr of type Tree which shares ownership of *this
	std::shared_ptr<Tree> shared_from_this() {
		return std::dynamic_pointer_cast < Tree
				> (inherited::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type Tree which shares ownership of *this
	std::shared_ptr<const Tree> shared_from_this() const {
		return std::dynamic_pointer_cast<const Tree>(
				inherited::shared_from_this());
	}

public:

	virtual ~Tree() = default;

	using Prop::cFeatureKeyCurrentTile;
	using Prop::cFeatureKeyStage;

	void setProperty(unsigned featureKey, Any value) override;
	void addToCollection(unsigned featureKey, EntityReference reference)
			override;
	void removeFromCollection(unsigned featureKey, EntityReference reference)
			override;

};

}

#endif //DE_UNISTUTTGART_KARA_TREE_H

