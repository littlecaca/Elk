#pragma once

#include "Layer.h"
#include <Elk/Core/Core.h>

namespace Elk
{
	class ELK_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer *layer);
		void PushOverlay(Layer *overlay);
		void PopLayer(Layer *layer);
		void PopOverlay(Layer *overlay);

		std::vector<Layer *>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer *>::iterator end() { return m_Layers.end(); }
	private:
		std::vector<Layer *> m_Layers;
		std::vector<Layer *>::size_type m_LayerInsertIndex;
	};

	
}