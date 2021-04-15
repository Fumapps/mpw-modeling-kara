/*
 * This file is generated. Do not change it manually.
 */

#ifndef DE_UNISTUTTGART_KARA_EDITORKARA_H
#define DE_UNISTUTTGART_KARA_EDITORKARA_H

#include <memory>
#include <string>
#include "ReadOnlyKara.h"

namespace kara {

class EditorKara: public virtual kara::ReadOnlyKara {

public:

	virtual ~EditorKara() = default;

	/// \brief returns a shared_ptr of type EditorKara which shares ownership of *this
	std::shared_ptr<EditorKara> shared_from_this() {
		return std::dynamic_pointer_cast < EditorKara
				> (basetypes::Entity::shared_from_this());
	}
	/// \brief returns a shared_ptr of const type EditorKara which shares ownership of *this
	std::shared_ptr<const EditorKara> shared_from_this() const {
		return std::dynamic_pointer_cast<const EditorKara>(
				basetypes::Entity::shared_from_this());
	}

};

}

#endif //DE_UNISTUTTGART_KARA_EDITORKARA_H

