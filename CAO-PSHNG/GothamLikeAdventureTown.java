import java.util.ArrayList;
import java.awt.Robot;
import java.awt.AWTException;
public class GothamLikeAdventureTown{
	public GothamLikeAdventureTown() throws AWTException {
		Robot robot = new Robot();
		String firstName[] = {"Vishal","Shahil","Kunal", "Sudarshan","Vikrant", "Ayush", "George","Kush", "Ayush (The other one)", "NA"};
		String lastName[] = {"Agarwal","Patel", "Amladi", "Seshadri","Singh", "Miller", "Anand", "Smith", "Ehrmantraut","NA"};
		String jobs[] = {"Unemployed/Canadian", "Memer", "YouTuber", "IT guy", "\"That\" guy", "Professional BTD5 player", "The guy who types the google autocompletes", "Ayush", "AP comp sci teacher", "Actor"};
		ArrayList<Person> dailyPlanetStreet= new ArrayList<Person>();
		boolean BG = true;
		boolean GG = true;
		for(int i = 0; i!=50;i++){
			if(i>47&&(BG||GG)){
				if(BG){
					dailyPlanetStreet.add(new BadGuy(    firstName[(int)(Math.random()*10)] +" "+ lastName[(int)(Math.random()*10)] , "That one BadGuy...", jobs[(int)(Math.random()*10)], 100, 10, 10, "Evil powers", true, 7, "EVIL words"));
					BG=false;
				}else{
					dailyPlanetStreet.add(new GoodGuy(    firstName[(int)(Math.random()*10)] +" "+ lastName[(int)(Math.random()*10)] , "That one Super hero...", jobs[(int)(Math.random()*10)], 100, 10, 10, "Generic Super Power", false, 7, "Words"));
					GG=false;
				}
			}else if (BG&&(int)(Math.random()*50) == 0){
					dailyPlanetStreet.add(new BadGuy(    firstName[(int)(Math.random()*10)] +" "+ lastName[(int)(Math.random()*10)] , "That one BadGuy...", jobs[(int)(Math.random()*10)], 100, 10, 10, "Evil powers", true, 7, "EVIL words"));
					BG=false;
			}else if (GG&&(int)(Math.random()*50) == 0){
					dailyPlanetStreet.add(new GoodGuy(    firstName[(int)(Math.random()*10)] +" "+ lastName[(int)(Math.random()*10)] , "That one Super hero...", jobs[(int)(Math.random()*10)], 100, 10, 10, "Generic Super Power", false, 7, "Words"));
					GG=false;
			}else{
				dailyPlanetStreet.add(new NormalGuy( firstName[(int)(Math.random()*10)] +" "+ lastName[(int)(Math.random()*10)] , jobs[(int)(Math.random()*10)]));
			}
		}
		System.out.print("SCANNING FOR PEOPLE IN \"GothamLikeAdventureTown\"");
		robot.delay(1000);
		for(int i = 0; i!=3;i++){
			System.out.print(".");
			robot.delay(500);
		}
		System.out.print("\n");
		for(int i = 0; i!=dailyPlanetStreet.size();i++){
			System.out.println(dailyPlanetStreet.get(i));
			robot.delay(50);
		}
		robot.delay(5000);

		for(int i = 0; i!=50;i++){
			System.out.println();
		}

		System.out.print("MOTION DETECTED\n");
		robot.delay(1000);
		System.out.print("TRIANGULATING ACTIVITY");
		robot.delay(1000);
		for(int i = 0; i!=3;i++){
			System.out.print(".");
			robot.delay(500);
		}
		System.out.print("\n\n\nREPORTING DETECTED ACTIONS\n\n\n");
		robot.delay(1000);
		ArrayList<Person> safetyLand = new ArrayList<Person>();
		ArrayList<Person> unfortunaelyFatallyWounded= new ArrayList<Person>();

		ArrayList<Person> alive = dailyPlanetStreet;
		ArrayList<Person> dead = safetyLand;
		ArrayList<Person> safe = unfortunaelyFatallyWounded;
		while(alive.size()>2){
			boolean BadGuyAttacked = false;
			for(int i = alive.size()-1; i!=0;i--){
				boolean someoneDied =true;
				if(alive.get(i) instanceof BadGuy&&!BadGuyAttacked){
					BadGuyAttacked = true;
					if(i!=0&&alive.get(i-1) instanceof NormalGuy){
						if(i<alive.size()-1 && alive.get(i+1) instanceof NormalGuy)
							if((int)(Math.random()*2) == 0)
								dead.add(alive.remove(i-1));
							else
								dead.add(alive.remove(i+1));
						else
							dead.add(alive.remove(i-1));
					}else if(i<alive.size()-1 && alive.get(i+1) instanceof NormalGuy){
						dead.add(alive.remove(i+1));
					}else{
						someoneDied = false;
					}
					if(someoneDied){
						int indexOfBadGuy=0;
						for(int x = alive.size()-1; x!=0;x--)
							if(alive.get(x) instanceof BadGuy)
								indexOfBadGuy = x;
						System.out.println(dead.get(dead.size()-1).getName()+" Died...");
						robot.delay(50);
						System.out.println(alive.get(indexOfBadGuy).getName()+" says: "+((BadGuy)alive.get(indexOfBadGuy)).getEvilLaugh()+"\n");
						robot.delay(500);
					}
				}
			}
			if(alive.size()>2){
				int savedPersonIndex;
				do{
					savedPersonIndex = (int)(Math.random()*alive.size());
				}while(!(alive.get(savedPersonIndex) instanceof NormalGuy));
				safe.add(alive.remove(savedPersonIndex));
				int couter = -1;
				do{
					couter++;
				}while(!(alive.get(couter) instanceof GoodGuy));
				System.out.println(safe.get(safe.size()-1).getName()+" has been saved!");
				robot.delay(50);
				System.out.println(alive.get(couter).getName()+" says: "+((GoodGuy)alive.get(couter)).getCatchPhrase()+"\n");
				alive.add((int)(Math.random() * alive.size()), alive.remove(couter) );
				robot.delay(500);
			}
		}
		for(int i = 0; i!=50;i++){
			System.out.println();
		}


		int indexOfGoodGuy = -1;
		do{
			indexOfGoodGuy++;
		}while(!(alive.get(indexOfGoodGuy) instanceof GoodGuy));
		int indexOfBadGuy = -1;
		do{
			indexOfBadGuy++;
		}while(!(alive.get(indexOfBadGuy) instanceof BadGuy));
		System.out.println(alive.get(indexOfGoodGuy).getName()+" encouters "+alive.get(indexOfBadGuy).getName());
		robot.delay(1000);
			int hero1Index;
			int hero2Index;
		if((int)(Math.random()*2) == 0){
			hero1Index = indexOfGoodGuy;
			hero2Index = indexOfBadGuy;
		}else{
			hero1Index = indexOfBadGuy;
			hero2Index = indexOfGoodGuy;
		}
			System.out.println(alive.get(hero1Index).getName()+ " attacks first!\n");
			robot.delay(1000);
		do{
			int damage = (int)(Math.random()*alive.get(hero1Index).getMaxDamage()+1);
			System.out.println(alive.get(hero1Index).getName()+" attacks with "+damage+" damage");
			robot.delay(500);
			int defence = (int)(Math.random()*alive.get(hero2Index).getDefenseAbilty()+1);
			System.out.println(alive.get(hero2Index).getName()+ " defends with "+ defence);
			robot.delay(50);
			if(defence>=damage){
				System.out.println(alive.get(hero2Index).getName()+ " successfully blocked " +alive.get(hero1Index).getName()+"'s attack!");
			}else{
				damage = (int)(Math.random()*alive.get(hero1Index).getMaxDamage()+1);
				alive.get(hero2Index).hpReduction(damage);
				System.out.println(alive.get(hero2Index).getName()+ "'s defence wasn't enough and " +alive.get(hero1Index).getName()+"'s attack does " +damage+ " damage!\n"+alive.get(hero2Index).getName()+"'s HP is now "+alive.get(hero2Index).getHitPoint());
			}
			robot.delay(1000);
			System.out.println();
			int temp = hero1Index;
			hero1Index = hero2Index;
			hero2Index = temp;
		}while(alive.get(hero2Index).getHitPoint()>0&&alive.get(hero1Index).getHitPoint()>0);
		robot.delay(5000);
		if(alive.get(hero2Index).getHitPoint()<=0)
			System.out.println(alive.get(hero2Index).getName()+" has died and "+alive.get(hero1Index).getName()+" WINS!");
		else
			System.out.println(alive.get(hero1Index).getName()+" has died and "+alive.get(hero2Index).getName()+" WINS!");
	}
	public static void main(String[]args) throws AWTException{
		GothamLikeAdventureTown app = new GothamLikeAdventureTown();
	}
}