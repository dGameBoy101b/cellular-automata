#include "square_model.h"

const Data::Model Data::SquareModel::getModel()
{
	const std::vector<Position<float>> VERTS = std::vector<Position<float>>({
		Position<float>(1, 1, 0),
		Position<float>(-1, 1, 0),
		Position<float>(-1, -1, 0),
		Position<float>(1, -1, 0)
		});
	const std::vector<std::vector<std::vector<Position<float>>::size_type>> FACES = std::vector<std::vector<std::vector<Position<float>>::size_type>>({
		std::vector<std::vector<Position<float>>::size_type>({
			0,
			1,
			2,
			3
		})
		});

	Model model = Model();

	for (std::vector<Position<float>>::const_iterator it = VERTS.begin();
		it != VERTS.end(); it++)
	{
		model.addVertex(*it);
	}
	for (std::vector<std::vector<std::vector<Position<float>>::size_type>>::const_iterator it = FACES.begin();
		it != FACES.end(); it++)
	{
		model.addFace(*it);
	}
	model.normalise();

	return model;
}
