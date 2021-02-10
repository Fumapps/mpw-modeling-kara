package de.unistuttgart.kara.view;

import de.unistuttgart.iste.sqa.mpw.framework.viewmodel.GameViewInput;
import de.unistuttgart.iste.sqa.mpw.framework.viewmodel.GameViewModel;
import de.unistuttgart.iste.sqa.mpw.framework.viewmodel.ViewModelCell;
import de.unistuttgart.iste.sqa.mpw.framework.viewmodel.ViewModelRow;
import de.unistuttgart.kara.WorldLoader;
import de.unistuttgart.kara.viewmodel.impl.KaraGameViewPresenter;
import de.unistuttgart.kara.kara.Kara;
import de.unistuttgart.kara.kara.KaraGame;
import org.junit.jupiter.api.BeforeAll;

import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class KaraViewTestBase {

    private int maxCharsPerCell = 2;
    private static Map<String, String> characterMap = new HashMap<>();
    private KaraGame game;
    protected Kara kara;
    protected GameViewInput viewInput;
    protected GameViewModel viewModel;

    @BeforeAll
    public static void setup() {
        initCharMapping();
    }

    protected void withWorld(String path) throws IOException {
        game = new KaraGame();
        WorldLoader.initializeFor(game).loadFromResourceFile(path);

        game.startGame();
        game.getPerformance().setDelayEnabled(false);

        var world = game.getWorld();
        kara = world.getKara();

        var presenter = new KaraGameViewPresenter(game);
        presenter.bind();
        viewInput = presenter;
        viewModel = presenter.getViewModel();

        game.setUserInputInterface(new UserInputInterfaceFake());
    }

    protected void clickPlay() {
        viewInput.playClicked();
    }

    protected void clickPause() {
        viewInput.pauseClicked();
    }

    protected void clickUndo() {
        viewInput.undoClicked();
    }

    protected void clickRedo() {
        viewInput.redoClicked();
    }

    protected void assertWorld(String expected) {
        var actual = new KaraViewModelStringifier(characterMap, maxCharsPerCell)
                .worldToExpectationString(viewModel);
        assertEquals(expected, actual);
        assertLocationsAreSet();
        assertSizeIsConsistent();
    }

    protected void assertButtons(String expected) {
        var actual = KaraViewModelStringifier.buttonBarToExpectationString(viewModel);
        assertEquals(expected, actual);
        assertLocationsAreSet();
        assertSizeIsConsistent();
    }

    private void assertLocationsAreSet() {
        List<ViewModelRow> rows = viewModel.getRows();
        for (int rowIndex = 0; rowIndex < rows.size(); rowIndex++) {
            ViewModelRow row = rows.get(rowIndex);
            List<ViewModelCell> cells = row.getCells();
            for (int columnIndex = 0; columnIndex < cells.size(); columnIndex++) {
                ViewModelCell cell = cells.get(columnIndex);
                assertEquals(columnIndex, cell.getLocation().getColumn());
                assertEquals(rowIndex, cell.getLocation().getRow());
            }

        }

    }

    private void assertSizeIsConsistent() {
        List<ViewModelRow> rows = viewModel.getRows();
        assertEquals(rows.size(), viewModel.getSize().getRowCount());
        for (ViewModelRow row : rows) {
            assertEquals(row.getCells().size(), viewModel.getSize().getColumnCount());
        }
    }

    protected void assertLog(String expected) {
        String actual = KaraViewModelStringifier.logToString(viewModel);
        assertEquals(expected, actual);
    }

    private static void initCharMapping() {
        characterMap.put("Kara", ">");
        characterMap.put("Kara[90]", "v");
        characterMap.put("Kara[180]", "<");
        characterMap.put("Kara[270]", "^");
        characterMap.put("Leaf", "*");
        characterMap.put("Tree", "##");
        characterMap.put("Mushroom", "@");
    }

}
