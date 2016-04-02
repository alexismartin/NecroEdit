#ifndef SRC_CLIENT_EDITOR_LEVELPANEL_HPP_
#define SRC_CLIENT_EDITOR_LEVELPANEL_HPP_

#include <Client/GUI2/GUI.hpp>
#include <Client/GUI2/Panels/BorderPanel.hpp>
#include <Client/GUI2/Panels/GridPanel.hpp>
#include <Client/GUI2/Widgets/Button.hpp>
#include <Client/GUI2/Widgets/Slider.hpp>
#include <Client/GUI2/Widgets/Text.hpp>
#include <cstddef>
#include <vector>

class Dungeon;

namespace gui2
{
class WidgetEvents;
}

class LevelPanel : public gui2::Container
{
public:

	/**
	 * Factory function.
	 */
	static gui2::Ptr<LevelPanel> make();

	void setSelectedLevel(std::size_t level);
	void deselectLevel();

	std::size_t getSelectedLevel() const;
	bool hasSelectedLevel() const;

	Dungeon * getDungeon() const;
	void setDungeon(Dungeon * dungeon);

	void updateDungeon();

	bool wasChanged();

	LevelPanel();

protected:

	virtual void init() override;

private:
	
	void selectLevel(std::size_t level);
	void setLevelListEntryColor(std::size_t level, bool highlight);
	void updateLevelListEntryRect(std::size_t level);
	void updateLevelButtons();
	
	void onResize();

	void onProcessContainer(gui2::WidgetEvents & events) override;

	Dungeon * dungeon;
	bool isAnyLevelSelected;
	std::size_t selectedLevel;
	bool wasLevelChanged;

	gui2::Ptr<gui2::Container> levelListContainer;
	std::vector<gui2::Ptr<gui2::Text>> levelListEntries;
	gui2::Ptr<gui2::Slider> levelListSlider;

	gui2::Ptr<gui2::Button> buttonAddLevel;
	gui2::Ptr<gui2::Button> buttonRemoveLevel;
	gui2::Ptr<gui2::Button> buttonDuplicateLevel;
	gui2::Ptr<gui2::Button> buttonMoveLevelUp;
	gui2::Ptr<gui2::Button> buttonMoveLevelDown;
};

#endif
