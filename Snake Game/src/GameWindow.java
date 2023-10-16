import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.Random; //used for generating food

public class GameWindow extends JPanel implements ActionListener
{
    static final int WINDOW_WIDTH = 500;
    static final int WINDOW_HEIGHT = 500;
    static final int UNIT_SIZE = 25;
    static final int MAX_UNITS = (WINDOW_WIDTH*WINDOW_HEIGHT)/UNIT_SIZE;
    static final int DELAY = 75; //game speed
    final int x[] = new int[MAX_UNITS];
    final int y[] = new int[MAX_UNITS];
    int bodyParts = 5;
    int applesEaten = 0;
    int appleX;
    int appleY;
    char direction = 'r';
    boolean running = false;
    Timer timer;
    Random random;

    GameWindow()
    {
        random = new Random();
        this.setPreferredSize(new Dimension(WINDOW_WIDTH, WINDOW_HEIGHT));
        this.setBackground(Color.black);
        this.setFocusable(true);
        this.addKeyListener(new MyKeyAdapter());
    }
    public void startGame()
    {
        cook();
        running = true;
        timer = new Timer(DELAY,this);
        timer.start();
    }
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        draw(g);

    }
    public void draw(Graphics g)
    {
        for (int i = 0; i < WINDOW_HEIGHT/UNIT_SIZE; i++)
        {
            g.drawLine(i*UNIT_SIZE, 0, i*UNIT_SIZE, WINDOW_HEIGHT);
            g.drawLine(0, i*UNIT_SIZE, WINDOW_WIDTH, i*UNIT_SIZE);
        }
        g.setColor(Color.red);
        g.fillOval(appleX, appleY, UNIT_SIZE, UNIT_SIZE);
    }
    public void cook() //make new food/apple
    {
        appleX = random.nextInt((int)(WINDOW_WIDTH/UNIT_SIZE))*UNIT_SIZE;
        appleY = random.nextInt((int)(WINDOW_HEIGHT/UNIT_SIZE))*UNIT_SIZE;

    }
    public void move()
    {

    }
    public void checkFood()
    {

    }
    public void checkCollision()
    {

    }
    public void gameOver(Graphics g)
    {

    }
    @Override
    public void actionPerformed(ActionEvent e)
    {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'actionPerformed'");
    }
    public class MyKeyAdapter extends KeyAdapter
    {
        @Override
        public void keyPressed(KeyEvent k)
        {

        }
    }
    
}
