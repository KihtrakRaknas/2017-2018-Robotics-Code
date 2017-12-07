public class GoodGuy extends SuperHero{
	private String catchPhrase;
	public GoodGuy(String name, String heroName, String job, int hitPoint, int maxDamage, int defenseAbility, String superPower,boolean cape,int powerLevel,String catchPhrase){
		super(name,heroName,job,hitPoint,maxDamage,defenseAbility,superPower,cape,powerLevel);
		this.catchPhrase = catchPhrase;
	}
	public String getCatchPhrase(){
		return catchPhrase;
	}
	public void powerLevelModification(){
		super.powerLevelModification(getPowerLevel()+(int)(Math.random()*10)+1);
	}
	public String toString(){
		return super.toString()+"\tCatch Phrase: "+catchPhrase;
	}
}