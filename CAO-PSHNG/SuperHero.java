public class SuperHero extends Person{
	private String heroName;
	private String superPower;
	private boolean cape;
	private int powerLevel;
	public SuperHero(String name, String heroName, String job, int hitPoint, int maxDamage, int defenseAbility, String superPower,boolean cape,int powerLevel){
		super(name,job,hitPoint,maxDamage,defenseAbility);
		this.superPower = superPower;
		this.cape = cape;
		this.powerLevel = powerLevel;
		this.heroName = heroName;
	}
	public String getSuperPower(){
		return superPower;
	}
	public boolean getCape(){
		return cape;
	}
	public int getPowerLevel(){
		return powerLevel;
	}
	public void powerLevelModification(int newLevel){
		powerLevel = newLevel;
	}
	public String toString(){
		return super.toString()+"\tSuper Power: " + superPower + "\t cape: " + cape +"\tPower Level: "+powerLevel;
	}
}