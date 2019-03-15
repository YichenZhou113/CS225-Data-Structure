/* Your code here! */
#include "maze.h"
#include <queue>
using namespace std;


SquareMaze::SquareMaze(){}

SquareMaze::mazeb::mazeb()
{
	visited = false;
	down = true;
  right = true;
}

void SquareMaze::makeMaze(int width, int height)
{
	DisjointSets dis;
  this->w = width;
	this->h = height;
	int area = width * height;
	//set the maze double array
	maze = new mazeb * [h];
	for(int i = 0; i < h; i++){
		maze[i] = new mazeb[w];
	}
	dis.addelements(area);
	int x;
	int y;
	int count = 0;
	srand(time(NULL));
	while(count != (area - 1))
	{
    y = rand() % h;
    x = rand() % w;
		bool flag = rand() % 2;
    if(flag == false && (y + 1 < h))
		{
			if((dis.find(x * h + y) != dis.find(x * h + y + 1)))
			{
				dis.setunion(dis.find(x * h + y), dis.find(x * h + y + 1));
				maze[x][y].down = false;
        count++;
			}
		}
		else if((x + 1 < w) && flag == true)
		{
			if((dis.find(x * h + y) != dis.find((x + 1) * h + y)))
			{
				dis.setunion(dis.find(x * h + y), dis.find((x + 1) * h + y));
				maze[x][y].right = false;
        count++;
			}
		}
	}
	return;
}

bool SquareMaze::canTravel(int x, int y, int dir) const
{
	//set labels in maze whether can pass
	if(dir == 0)
	{
    if(maze[x][y].right == true)
			return false;
    else if(x == w-1)
			return false;
		else
			return true;
	}
	else if(dir == 1)
	{
		if(maze[x][y].down == true)
			return false;
    else if(y == h-1)
  		return false;
		else
			return true;
	}
	else if(dir == 2)
	{
		if(x == 0)
			return false;
		else if(maze[x-1][y].right == true)
			return false;
		else
			return true;
	}
	else if(dir == 3)
	{
		if(maze[x][y-1].down == true)
			return false;
    else if(y == 0)
  		return false;
		else
			return true;
	}
	else{
		return false;
	}
}

void SquareMaze::setWall(int x, int y, int dir, bool exists)
{
	//sets the wall to be existing or not
  if(dir == 0){
		maze[x][y].right = exists;
	}else if(dir == 1){
		maze[x][y].down = exists;
	}
	return;
}

vector<int> SquareMaze::solveMaze()
{
	//initialize the maze and then check whether can pass
	for(int i = 0; i < w; i++){
		for(int j = 0; j < h; j++){
			maze[i][j].visited = false;
		}
	}
  vector<int> dist(w * h, 0);
  vector<int> prev(w * h, -1);
	queue <int> q;
	q.push(0);
  int front, x, y;
  maze[0][0].visited = true;
	while(!q.empty())
	{
		front = q.front();
		q.pop();
		y = front / h;
		x = front % h;
    //right
    if(canTravel(x, y, 0) && maze[x+1][y].visited==0)
		{
			dist[front + 1] = dist[front] + 1;
      prev[front + 1] = front;
      maze[x + 1][y].visited = true;
			q.push(front + 1);
		}
    //left
		if(canTravel(x, y, 2) && maze[x - 1][y].visited == 0)
		{
			dist[front - 1] = dist[front] + 1;
      prev[front - 1] = front;
      maze[x - 1][y].visited = true;
			q.push(front - 1);
		}
    //up
		if(canTravel(x, y, 3) && maze[x][y - 1].visited == 0)
		{
			dist[front - h] = dist[front] + 1;
      prev[front - h] = front;
      maze[x][y - 1].visited = true;
			q.push(front - h);
		}
    //down
    if(canTravel(x, y, 1) && maze[x][y + 1].visited == 0)
		{
			dist[h + front] = dist[front] + 1;
      prev[h + front] = front;
      maze[x][y + 1].visited = true;
			q.push(front + h);
		}
	}
	int max = w * h - w;
	for(int i = 1; i < w; i++){
		if(dist[(w * h) - w + i] > dist[max]){
			max = (w*h)- w + i;
		}
	}
  vector<int> dir;
  int next = max;
	while(prev[next] != -1)
	{
		x = front / h;
		y = front % h;
    //left
		if(prev[next] == next-1)
		{
      next = prev[next];
      dir.insert(dir.begin(), 0);
		}
    //right
    if(prev[next] == next+1)
		{
      next = prev[next];
      dir.insert(dir.begin(), 2);
		}
    //up
		if(prev[next] == next - h)
		{
      next = prev[next];
      dir.insert(dir.begin(), 1);
		}
    //down
		if(prev[next] == next + h)
		{
      next = prev[next];
      dir.insert(dir.begin(), 3);
		}

	}
	return dir;
}

PNG * SquareMaze::drawMaze()const
{
	//set the borders and background
	PNG * p = new PNG();
	p->resize(w * 10 + 1, h * 10 + 1);
  for(int i = 0; i < h * 10 + 1; i++)
	{
		(*p).getPixel(0,i)->h=0; (*p).getPixel(0,i)->s=0; (*p).getPixel(0,i)->l=0;
	}
	for(int i = 10; i < w * 10 + 1; i++)
	{
		(*p).getPixel(i,0)->h=0; (*p).getPixel(i,0)->s=0; (*p).getPixel(i,0)->l=0;
	}
	for(int i = 0; i < w; i++)
	{
		for(int j = 0; j < h; j++)
		{
      if(maze[i][j].down == true)
			{
				for(int k = 0; k <= 10; k++)
				{
					 (*p).getPixel(i * 10 + k, (j+1) * 10)->h = 0;
					 (*p).getPixel(i * 10 + k, (j+1) * 10)->s = 0;
					 (*p).getPixel(i * 10 + k, (j+1) * 10)->l = 0;
				}
			}
      if(maze[i][j].right == true)
			{
				for(int k = 0; k <= 10; k++)
				{
					 (*p).getPixel((i+1) * 10, j * 10 + k)->h = 0;
					 (*p).getPixel((i+1) * 10, j * 10 + k)->s = 0;
					 (*p).getPixel((i+1) * 10, j * 10 + k)->l = 0;
				}
			}
		}
	}
	return p;
}

PNG * SquareMaze::drawMazeWithSolution()
{
	PNG * solution = drawMaze();
	vector<int> path = solveMaze();
	int x = 5;
	int y = 5;
	for(int k =0; k < int(path.size()); k++)
	{
    //right
		if(path[k] == 0)
		{
			for(int i = 0; i < 11; i++)
			{
				(*solution).getPixel(x+i, y)->h = 0;
				(*solution).getPixel(x+i, y)->s = 1;
				(*solution).getPixel(x+i, y)->l = 0.5;
				(*solution).getPixel(x+i, y)->a = 1;
			}
			x += 10;
		}
		//down
		else if(path[k] == 1)
		{
			for(int i = 0; i < 11; i++)
			{
				(*solution).getPixel(x, y+i)->h = 0;
				(*solution).getPixel(x, y+i)->s = 1;
				(*solution).getPixel(x, y+i)->l = 0.5;
				(*solution).getPixel(x, y+i)->a = 1;
			}
			y += 10;
		}
    //left
		else if(path[k] == 2)
		{
			for(int i = 0; i < 11; i++)
			{
				(*solution).getPixel(x-i, y)->h = 0;
				(*solution).getPixel(x-i, y)->s = 1;
				(*solution).getPixel(x-i, y)->l = 0.5;
				(*solution).getPixel(x-i, y)->a = 1;
			}
			x -= 10;
		}
    //up
    else if(path[k] == 3)
    {
      for(int i = 0; i < 11; i++)
      {
				(*solution).getPixel(x, y-i)->h = 0;
				(*solution).getPixel(x, y-i)->s = 1;
				(*solution).getPixel(x, y-i)->l = 0.5;
				(*solution).getPixel(x, y-i)->a = 1;
      }
      y -= 10;
    }
	}
	for(int i = 0; i < 9; i++)
	{
		(*solution).getPixel(x - 4 + i, y + 5)->h = 0;
		(*solution).getPixel(x - 4 + i, y + 5)->s = 0;
		(*solution).getPixel(x - 4 + i, y + 5)->l = 1;
	}
	return solution;
}
